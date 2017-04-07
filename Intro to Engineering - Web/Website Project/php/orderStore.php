<?php
/**
 * OrderStore Persistence Class
 *
 * @author Reid Wixom
 */
class OrderStore {
	
	// database connection info
	function connect() {
		$servername = "courses";
		$username = "z1652867";
		$password = "1992Dec26";
		$port = "3306";
		$dbname = "z1652867";

		$dbh = new PDO('mysql:host=' . $servername . ';'
						. 'port=' . $port . ';'
						.'dbname=' . $dbname, 
						$username,
						$password
		);
		return $dbh;
	}
	
	public function submitOrder($transID, $custName, $address, $prodID, $qty) {
		$dbh = $this->connect();
	    $sth = $dbh->prepare('
	    	insert into orders values (:transID, :name, :address, 0, :prodID, :qty)
		');

	    $result = $sth->execute([
	    	':transID' => $transID,
	    	':name' => $custName,
	    	':address' => $address,
	    	':prodID' => $prodID,
	    	':qty' => $qty
	    ]);

		return $result;

	}
	public function getOpenOrders() {
		$dbh = $this->connect();
	    $sth = $dbh->prepare('
	    	select * from orders where fulfilled=0
		');
		$sth->execute();

	    $rows = $sth->fetchAll();

	    $orders = [];

	    foreach($rows as $row) {
	    	$orders[] = new Order($row);
	    }

	    return $orders;

	}
	public function getOrder($id) {
		$dbh = $this->connect();
	    $sth = $dbh->prepare('
	    	select * from orders where transID=:id
		');
		$sth->execute([
			':id' => $id
		]);

		$row = $sth->fetch();

		return new Order($row);



	}
	public function setAsCompleted($id) {
		$dbh = $this->connect();
	    $sth = $dbh->prepare('
	    	update orders set fulfilled=1 where transID=:id
		');
		$result = $sth->execute([
			':id' => $id
		]);

		return $result;
	}
}
class Order {
	var $id;
	var $address;
	var $name;
	var $prodID;
	var $prodQty;
	var $fulfilled;

	function __construct($row) {
		$this->id = $row ['transID'];
		$this->address = $row ['shipAddress'];
		$this->name = $row ['custName'];
		$this->prodQty = $row ['quantity'];
		$this->prodID = $row ['prodID'];
		$this->fulfilled = $row ['fulfilled'];		
	}
}

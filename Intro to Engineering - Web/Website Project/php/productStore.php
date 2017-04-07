<?php
/**
 * Product Store Persistence Class
 *
 * @author Reid Wixom
 */
class ProductStore {
	
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
	
	// access functions
	public function getProducts() {
		$dbh = $this->connect();
	    $sth = $dbh->prepare('
	    	select * from product
		');

	    $sth->execute();

	    $rows = $sth->fetchAll();

	    $products = [];

	    foreach($rows as $row) {
	    	$products[] = new Product($row);
	    }

		return $products;
	}
	public function getProduct($id) {
		$dbh = $this->connect();
		$sth = $dbh->prepare('
			SELECT * from product where prodID = :id
		');
		$sth->execute([
			':id' => $id
		]);

		return new Product($sth->fetch(PDO::FETCH_ASSOC));
	}
	public function updateProductInventory($id, $qty)
	{
		$dbh = $this->connect();
		$sql="UPDATE product SET quantity=quantity+:qty WHERE prodID=:id";
		$sth = $dbh->prepare($sql);
		$result = $sth->execute([
			':id' => $id,
			':qty' => $qty
		]);
		return $this->getProduct($id);
	}
	public function searchByDescription($string) {
		$dbh = $this->connect();
		$string = "%" . $string . "%";
		$sth = $dbh->prepare('
			select * from product where description like :string
		');
		$sth->execute([
			':string' => $string
		]);

		$rows = $sth->fetchAll();
		$products = [];

	    foreach($rows as $row) {
	    	$products[] = new Product($row);
	    }
	    return $products;

	}
}
class Product {
	var $id;
	var $description;
	var $price;
	var $quantity;
	// create employee from array
	function __construct($row) {
		$this->id = $row ['prodID'];
		$this->description = $row ['description'];
		$this->price = $row ['price'];
		$this->quantity = $row ['quantity'];
	}
}

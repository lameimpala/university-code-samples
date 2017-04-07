<?php
error_reporting(E_ALL ^ E_DEPRECATED);
$hostname = "courses";
$username = "z1652867";
$password = "1992Dec26";
$db = "z1652867";

$hostname2="blitz.cs.niu.edu";
$username2="student";
$password2="student";
$db2="csci467";
$port2="3306";

//connect to the database 1
$conn1 = mysql_connect($hostname,$username,$password);
if (!$conn1) {
  die("Could not connect: " . mysql_error());
			}
//select the database 1
$db_selected = mysql_select_db($db, $conn1);
if (!$db_selected) {
   die ("Can\"t use " . $db . mysql_error());
					}
//connect to the database 2
$conn2 = mysql_connect($hostname2,$username2,$password2);
if(!$conn2){
  die("Could not connect: " . mysql_error());
			}
//select the database 2
$db_selected = mysql_select_db($db2, $conn2);
if (!$db_selected) {
   die ("Can\"t use " . $db2 . mysql_error());
					}
$dbh = new PDO('mysql:host=' . $hostname . ';'
				. 'port=' . $port2 . ';'
				.'dbname=' . $db, 
				$username,
				$password
);

$sql1="SELECT * FROM parts;";
$result1=mysql_query($sql1,$conn2);
$numrows=mysql_num_rows($result1);

for($i='0';$i<$numrows;$i++)
{
	$row=mysql_fetch_array($result1);
	echo'<p>',($row[0]),'</p>';
	echo'<td>',($row[1]),'</td>';
	echo'<td>',($row[2]),'</td>';
	$sth = $dbh->prepare('
			INSERT INTO product(prodID,description,price,quantity) VALUES( :id, :description, :price, :qty )
	');
	$result = $sth->execute([
			':id' => $row[0],
			':description' => $row[1],
			':price' => $row[2],
			':qty' => 2
	]);
	echo "<p>" . $result . "</p>";
}


mysql_close($conn1);
mysql_close($conn2);
				
?>
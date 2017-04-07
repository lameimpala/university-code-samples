<?php
$dbh = new PDO('mysql:host=courses', 'z1693990', '1995Jan24');

$dbh->exec('
	use z1693990
');

$sth = $dbh->prepare('
	SELECT * FROM s where city = :city
');
$sth->execute([
	':city' => $_POST['city'],
]);

?>
<html>
<head>
	<title>
		Suppliers
	</title>
</head>
<body>
	<center>
	<h1>
Suppliers in <?php echo $_POST['city'] ?>
</h1>

<table border="1">
	<tr>
		<td>
			City
		</td>
		<td>
			Supplier Name
		</td>
		<td>
			Status
		</td>
	</tr>
	<?php 
	while($row = $sth->fetch(PDO::FETCH_ASSOC)) {
		echo "<tr>";
		echo "<td>" . $row['city'] . "</td>";
		echo "<td>" . $row['sname'] . "</td>";
		echo "<td>" . $row['status'] . "</td>";
		echo "</tr>";
	}


?>


</table>








</center>
</body>
</html>
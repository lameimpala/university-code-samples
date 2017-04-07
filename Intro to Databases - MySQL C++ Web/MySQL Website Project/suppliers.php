<?php
$dbh = new PDO('mysql:host=courses', 'z1693990', '1995Jan24');

$dbh->exec('
	use z1693990
');

$sth = $dbh->prepare('
	SELECT * FROM s
	Inner join sp
	on sp.snum = s.snum
	Inner Join p
	on p.pnum = sp.pnum
');
$sth->execute();

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
Suppliers
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
				<td>
			Part Name
		</td>
		<td>
			Color
		</td>
		<td>
			Weight
		</td>
	</tr>
	<?php 
	while($row = $sth->fetch(PDO::FETCH_ASSOC)) {
		echo "<tr>";
		echo "<td>" . $row['city'] . "</td>";
		echo "<td>" . $row['sname'] . "</td>";
		echo "<td>" . $row['status'] . "</td>";
		echo "<td>" . $row['pname'] . "</td>";
		echo "<td>" . $row['color'] . "</td>";
		echo "<td>" . $row['weight'] . "</td>";
		echo "</tr>";
	}


?>


</table>








</center>
</body>
</html>
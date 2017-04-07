<?php
$dbh = new PDO('mysql:host=courses', 'z1693990', '1995Jan24');

$dbh->exec('
	use z1693990
');
$parts = $dbh->prepare('
	SELECT pname, pnum from p
');
$parts->execute();
$suppliers = $dbh->prepare('
	SELECT sname, snum from s group by sname
');
$suppliers->execute();
$supplier_city = $dbh->query('
	SELECT city from s group by city
')

?>
<html>
<head>
	<title>
		CSCI 466
	</title>
</head>
<body>
	<center>
<h1>
New Supplier
</h1>
<form  action="new_supplier.php" method="post">
	<p>
		New Supplier Name:
		<input type="text" name="name">
	</p>
	<p>
		New City Name:
		<input type="text" name="city">
		</p>
			<p>
		Status:
		<input type="text" name="status">
		</p>
		<input type="submit">
</form>

<h1>
New Part
</h1>
<form  action="new_part.php" method="post">
	<p>
		New Part Name:
		<input type="text" name="name">
	</p>
		<p>
		New Part Color:
		<input type="text" name="color">
	</p>
	<p>
		New Part Weight (lbs):
		<input type="text" name="weight">
	</p>
		<input type="submit">
</form>

<h1>
Link Part to Supplier
</h1>
<form  action="link_part.php" method="post">
	<p>
		Part
	</p>
	<select name="part">
		<?php
			while($row = $parts->fetch(PDO::FETCH_ASSOC)) {
				echo "<option value='" . $row['pnum'] . "'>" . $row['pname'] . "</option>";
			}

		?>
	</select>
	<p>
		Supplier
	</p>
		<select name="supplier">
		<?php
			while($row = $suppliers->fetch(PDO::FETCH_ASSOC)) {
				echo "<option value='" . $row['snum'] . "'>" . $row['sname'] . "</option>";
			}

		?>
	</select>
</br>
		<input type="submit">
	</form>

	<h1>
View Suppliers By City
</h1>
<form  action="supplier_by_city.php" method="post">
	<select name="city">
		<?php
			while($row = $supplier_city->fetch(PDO::FETCH_ASSOC)) {
				echo "<option value='" . $row['city'] . "'>" . $row['city'] . "</option>";
			}

		?>
	</select>
</br>
		<input type="submit">
	</form>

<a href="suppliers.php"><h1>Supplier Table</h1></a>
</center>
</body>
</html>



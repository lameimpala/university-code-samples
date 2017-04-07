<?php

$dsn = 'mysql:host=courses;dbname=z1693990';
$dbh = new PDO($dsn, 'z1693990', '1995Jan24');

if ($_POST['name'] == '') {
	echo "Error! Name is Blank";
}
else {

	$sth = $dbh->prepare('
		INSERT INTO s (sname, city, status) VALUES(:supplier, :city, :status)
	');

	$result = $sth->execute([
		':supplier' => $_POST['name'],
		':city' => $_POST['city'],
		':status' => $_POST['status'],
	]);

	if ($result) {
		echo "Insertion was successful";
	}
	else {
		echo "Insertion failed.";
	}
}
?>
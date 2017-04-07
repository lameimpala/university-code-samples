<?php

$dsn = 'mysql:host=courses;dbname=z1693990';
$dbh = new PDO($dsn, 'z1693990', '1995Jan24');

if ($_POST['name'] == '') {
	echo "Error! Name is Blank";
}
else {

	$sth = $dbh->prepare('
		INSERT INTO p (pname, color, weight) VALUES(:name, :color, :weight)
	');

	$result = $sth->execute([
		':name' => $_POST['name'],
		':color' => $_POST['color'],
		':weight' => $_POST['weight'],
	]);

	if ($result) {
		echo "Insertion was successful";
	}
	else {
		echo "Insertion failed.";
	}
}








?>
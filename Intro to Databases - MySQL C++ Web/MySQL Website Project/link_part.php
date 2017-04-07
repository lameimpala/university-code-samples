<?php

$dsn = 'mysql:host=courses;dbname=z1693990';
$dbh = new PDO($dsn, 'z1693990', '1995Jan24');

$sth = $dbh->prepare('
	INSERT INTO sp (snum, pnum) VALUES (:snum, :pnum)
');
$result = $sth->execute([
	':snum' => $_POST['supplier'],
	':pnum' => $_POST['part'],
]);

if ($result) {
	echo "Insertion was successful";
}
else {
	echo "Insertion failed.";
}


?>
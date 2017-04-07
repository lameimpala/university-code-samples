<?php

$custName = $_POST['custName'];
$ccNum = $_POST['creditCardNumber'];
$ccExpM = $_POST['creditCardExpirationMonth'];
$ccExpY = $_POST['creditCardExpirationYear'];
$address = $_POST['shipAddress'];
$totalCost = $_POST['total'];
$prodID = $_POST['prodID'];
$qty = $_POST['qty'];

$response = $_SESSION['controller']->processCC($ccNum, $ccExpM, $ccExpY, $totalCost, $custName);



$result = preg_match('/authorization code: ([\d]+)/',$response,$transID);
$transID = str_replace('authorization code: ', '', $transID[0]);
if (!$result) {
	echo "<h1>Card Declined</h1>";
} else {
	echo "<legend>Card Accepted</legend>";
	echo "<p><b>Authorization Code: </b>" . $transID . "</p>";
	$result = $_SESSION['controller']->submitOrder($transID, $custName, $address, $prodID, $qty);
}
?>
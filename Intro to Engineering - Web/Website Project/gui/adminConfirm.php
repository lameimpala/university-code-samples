

<div class="container">
<div class ="header">
	<legend>Change Confirmation</legend>
</div>
<?php
	$_SESSION['controller']->setShippingFee($_POST['editShip']);
	$_SESSION['controller']->setSalesTax($_POST['editTax']/100);
	$newShipping=$_SESSION['controller']->getShippingFee();
	$newTax=$_SESSION['controller']->getSalesTax() * 100;
	echo  "<b>Shipping fee:</b> ". $newShipping ."<br>";
	echo  "<b>Tax rate:</b> " . $newTax ."%";
?>

</div>
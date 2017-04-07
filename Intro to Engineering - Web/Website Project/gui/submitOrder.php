<?php

$id = $_POST['id'];
$qty = $_POST['quantity'];

$noFee=$_SESSION['controller']->calculateCostNoFee($id,$qty);
$totalCost = $_SESSION['controller']->calculateCost($id, $qty);
$shipping=$_SESSION['controller']->getShippingFee();
$tax=$_SESSION['controller']->getSalesTax() * 100;

?>
<div class="container">

<legend>
	<b>Item Total:</b> <?php echo "$". $noFee . " " ?> <br>
	<b>Shipping Rate:</b> <?php echo "$". $shipping ." "; ?> <br>
	<b>Tax Rate:</b> <?php echo " ". $tax . "%"; ?> <br>
	<b>Total Cost: </b> <?php printf("$%.2f", $totalCost) ?> 
</legend>

<form method="post" action="index.php?page=placeOrder">

<p>Name: 
<input class="form-control" type="text" placeholder="John Doe" name="custName"></p>
<p>Shipping Address: 
<input class="form-control" name="shipAddress" placeholder="123 Bakers Street Dekalb" type="text"></p>
<p>Credit Card Number: 
<input class="form-control" type=text pattern="[0-9]{13,16}" name="creditCardNumber"></p>
<p>Credit Card Expiration Month(MM): 
<input class="form-control" type=text pattern="[0-9]{2}" name="creditCardExpirationMonth"></p>
<p>Credit Card Expiration Year(YYYY): 
<input class="form-control" type=text pattern="[0-9]{4}" name="creditCardExpirationYear"></p>
<input name="total" value="<?php echo $totalCost ?>" style="display:none">
<input name="qty" value="<?php echo $qty ?>" style="display:none">
<input name="prodID" value="<?php echo $id ?>" style="display:none">
<input class="btn btn-lg btn-primary" type="submit" value="Submit">
</form>

</div>
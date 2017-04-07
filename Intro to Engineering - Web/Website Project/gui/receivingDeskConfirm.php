

<div class="container">
<div class="header">
	<legend>Confirming Item Quantity Update</legend>
</div>
	<?php
		$_SESSION['controller2']->updateProductInventory($_POST['id'], $_POST['newQty']);
		$updated=$_SESSION['controller2']->getProduct($_POST['id']);
		echo "<table style='width:70%''>";
		echo "<caption align='top'>Updated Item Information</caption>";
		echo "<tr>";
		echo "<th>Item ID</th>";
		echo "<th>Item Description</th>";
		echo "<th>New Current Quantity</th>";
		echo "</tr>";
		echo "<tr>";
		echo "<td>". $updated->id . "</td>";
		echo "<td>". $updated->description ."</td>";
		echo "<td>". $updated->quantity ."</td>";
		echo "</table>";
	?>
	<hr>
</div>
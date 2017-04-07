

<div class="container">
<div class="header">
	<legend>Receiving Desk Information</legend>
</div>
<div class='col-sm-4 col-lg-4 col-md-4'>
	<h4>Enter Product ID:</h4>
		<form method='POST' action='index.php?page=receivingDeskEdit'>
		Item ID: <input type="text" name="inItemID" style="margin-bottom:10px">
		<input class="btn btn-primary" type = "submit" style="display:block;">
</form>
</div>
<div class='col-sm-4 col-lg-4 col-md-4'>
	<h4>Search By Description:</h4>
		<form method='POST' action='index.php?page=receivingDeskEditDesc'>
		Keyword: <input type="text" name="inItemDesc" style="margin-bottom:10px">
		<input class="btn btn-primary" type="submit" style="display:block;">
		</form>
</div>
		<legend>List of Items</legend>
		<?php
		$lists=$_SESSION['controller2']->getProducts();

		echo "<table class='table table-striped'>";
		echo "<tr>";
		echo "<th>Item ID</th>";
		echo "<th>Item Description</th>";
		echo "<th>Item Quantity</th>";
		echo "</tr>";
		foreach($lists as $lists)
		{
			echo "<tr>";
			echo "<td>". $lists->id . "</td>";
			echo "<td>". $lists->description ."</td>";
			echo "<td>". $lists->quantity ."</td>";
		}
		echo "</table>"
		?>
</div>
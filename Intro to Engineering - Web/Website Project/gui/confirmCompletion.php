<div class="container">

<h3>
Confirming Order Completion
</h3>
  <table class="table table-striped">
    <thead>
      <tr>
        <th>Customer Name</th>
        <th>Shipping Address</th>
        <th>Transaction ID</th>
        <th>Product ID</th>
        <th>Quantity</th>
      </tr>
    </thead>
    <tbody>
<?php 

		$order = $_SESSION['orderController']->getOrder($_GET['order']);
		echo "<tr>";
        echo "<td>" . $order->name . "</td>";
        echo "<td>" . $order->address . "</td>";
        echo "<td>" . $order->id . "</td>";
        echo "<td>" . $order->prodID . "</td>";
        echo "<td>" . $order->prodQty . "</td>";
        echo "<tr>";
?>
</tbody>
</table>
<form method="POST" action="index.php?page=viewOpenOrders">
<input type="text" name='id' value='<?php echo $order->id ?>' style="display:none;">
<input class="btn btn-success btn-lg" type="submit" name="confirmed" value="Complete">
</form>
</div>
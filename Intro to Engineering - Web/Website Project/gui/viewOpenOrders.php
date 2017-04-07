  
<div class="container">
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
      if (isset($_POST['id'])) {
        $_SESSION['orderController']->setAsCompleted($_POST['id']);
      }
      $orders = $_SESSION['orderController']->getOpenOrders();
      foreach($orders as $order) {
        echo "<tr>";
        echo "<td>" . $order->name . "</td>";
        echo "<td>" . $order->address . "</td>";
        echo "<td>" . $order->id . "</td>";
        echo "<td>" . $order->prodID . "</td>";
        echo "<td>" . $order->prodQty . "</td>";
        echo "<td><a href='index.php?page=printShippingLabel&order=" . $order->id . "' class='btn btn-primary btn-sm active' role='button' style='margin-right:35px'>Print Label</a><a href='index.php?page=confirmCompletion&order=" . $order->id ."' class='btn btn-sm btn-success role='button'>Mark as Shipped</a></td>";
        echo "<tr>";
      }

    ?>
    </tbody>
  </table>

  </div>
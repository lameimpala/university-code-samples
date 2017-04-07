<?php 
    
    if (isset($_GET['search'])) {
        $products = $_SESSION['controller']->searchByDescription($_GET['search']);
    } else {
     $products = $_SESSION['controller']->getProducts();
 }
 
    

	foreach($products as $product) {
        echo "<div class='col-sm-4 col-lg-4 col-md-4'>";
        echo "<div class='thumbnail'>";
        echo "<a href='index.php?page=product&id=" . $product->id ."'>";
        echo "<img src='http://www.socialmediatoday.com/sites/default/files/post_main_images/tools_5.jpg' height=150 width=320 alt=''>";
        echo "<div class='caption'>";
        echo "<h4 class='pull-right'>$" . $product->price . "</h4>";
        echo "<h3>" . $product->description . "</h3>";
        echo "<p><b>Quantity: </b>" . $product->quantity . "</p>";
        echo "</div></div></a></div>";
	}
?>

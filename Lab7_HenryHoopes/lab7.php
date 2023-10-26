<html>
	<head>
		<link rel="stylesheet" href="style.css">
	</head>
	<body>
		<h1>EECS Lab 7 Practice 4</h1>
		<p> You have chosen size: <?php echo $_POST["size"]; ?></p>
		<?php
			$size = intval($_POST["size"]);
			echo "<table><tr><td>Values</td>";
			for($i = 1; $i <= $size; $i++){
				echo "<td> $i </td>";
			}	
			echo "</tr>";

			for($i=1; $i<=$size; $i++){
				echo "<tr><td> $i </td>";
				for ($j = 1; $j<=$size; $j++){
					echo "<td>", ($i*$j), "</td>";
				}
				echo "</tr>";
			}
			echo "</table>";
		?>
		</table>
	</body>
</html>

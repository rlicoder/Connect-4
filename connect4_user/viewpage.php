<!doctype html>
<html lang="en">
<head>
	<meta http-equiv="Content-type" content="text/html; charset=utf-8" />
	<link rel="stylesheet" href="style2.css" type="text/css" media="all" />
</head>
<body>

	<div id="header">
		<div class="shell">
			
			<div id="head">
				<h1><a href="admin.html">Administration</a></h1>
				<div class="right">
					<p>
						Welcome Administrator |
                                                <a href="index.php"><strong> Logout</strong></a>
					</p>
				</div>
			</div>
			<div id="navigation">
				<ul>
				    <li><a href="admin.html" class="active"><span>Home</span></a></li>
                                    <li><a href="viewpage.php" class="active"><span>View</span></a></li>
                                    <li><a href="edit.php" class="active"><span>Edit</span></a></li>
				</ul>
			</div>
		</div>
	</div>
    <div>
        <p align="center">View all users' information<br><br>
    </div>
    <?php 
        
        if(isset($_GET['page'])){
            $page=$_GET['page'];
        }
        else{
            $page=1;
        }
        
        $pagesize=1;

        $conn= new mysqli("localhost","root","","connect4");
        if($conn->connect_error){
            die("Connection failed: " . $conn->connect_error);
        }
        $query=("select count(1) from entity_user");
        $result = $conn->query($query);
        $row=mysqli_fetch_row($result);
        $recordcount=$row[0]; 

        if($recordcount==0)
            $pagecount=0;
        else if($recordcount<$pagesize ||$recordcount==$pagesize){
                $pagecount=1;
            }
        else if($recordcount%$pagesize==0){
                $pagecount=$recordcount/$pagesize;
            }
        else 
                $pagecount=(int)($recordcount/$pagesize)+1;

    ?>

    <table id="view">
        <tr>
            <td>Username</td>
            <td>Password</td>
            <td>Email</td>
        </tr>
    <?php 
    $sql=($page-1)*$pagesize;
    $result_=$conn->query("select * from entity_user limit {$sql},{$pagesize}");
    while($row=mysqli_fetch_row($result_))
    {   

        echo("<tr />");
        echo("<td>$row[0]</td>");
        echo("<td>$row[1]</td>");
        echo("<td>$row[2]</td>");
        echo("<tr />");
    }
    $conn->close();
    ?>
        <div>
            <p align="center">
            <?php
        if($page==1){
        echo("Home"." ");
    }
    else
        echo("<a href=viewpage.php?page=1>Home </a>");

    if($page==1){
         echo("<-Previous"." ");
    }
    else 
        echo("<a href=viewpage.php?page=".($page-1)."><-Previous </a>");

    if($page==$pagecount){
        echo("Next->"." ");
    }
    else 
        echo("<a href=viewpage.php?page=".($page+1).">Next-> </a>");
    if($page==$pagecount){
        echo("Last");
    }
    else 
        echo("<a href=viewpage.php?page=".$pagecount.">Last</a>");
    
    ?>
            </p>
    </div>
    </table>
    <div>
        <p align="center">
        <?php
        echo("Page: ".$page."/".$pagecount."<br />");
        ?>
        </p>
    </div>
</body>
</html>
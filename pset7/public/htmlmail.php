<!-- did't work yet!-->
<!-- use from header.php -->
<?php
//https://manual.cs50.net/mail/
//http://cs50.stackexchange.com/questions/11101/how-do-i-send-an-email-with-php
    require("libphp-phpmailer/class.phpmailer.php");

    $mail = new PHPMailer();
    $mail->IsSMTP();
    $mail->SMTPAuth = true;
    $mail->SMTPSecure = "tls";
    $mail->Host = "smtp.gmail.com"; // change to your email host
    $mail->Port = 587; // change to your email port
    $mail->Username = "alvinng222@gmail.com"; //"myGmailAddress@gmail.com"; // change to your username
    //$mail->Password = myOneTimePasswordBecauseOfTwoStepAuth"; // change to your email password
    $mail->setFrom("alvinng222@gmail.com"); // change to your email password
    $mail->AddAddress("alvinng222@gmail.com"); //"myOtherGmailAddress@gmail.com"); // change to user's email address
    $mail->Subject = "trial"; // change to email's subject
    $mail->Body = "<h1>hello, world!</h1>"; // change to email's body, add the needed link here

    if ($mail->Send() == false)
    {
        die($mail->ErrInfo);
    }
    else
    {
        echo "It worked!\n";
    }
?>

<!-- Remember mail function will not work in Local server. -->
/*
$to = "alvinng222@gmail.com";
$subject = "HTML email";

$message = 
require("../views/htmlmail_view.php");
;

// Always set content-type when sending HTML email
$headers = "MIME-Version: 1.0" . "\r\n";
$headers .= "Content-type:text/html;charset=UTF-8" . "\r\n";

// More headers
$headers .= 'From: <alvinng222@gmail.com>' . "\r\n";
$headers .= 'Cc: alvinng222@gmail.com' . "\r\n";

mail($to,$subject,$message,$headers);

?>

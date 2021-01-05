Search()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_start_transaction("01");

		web_url("blazedemo.com", 
		"URL=http://blazedemo.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://blazedemo.com/favicon.ico", "Referer=https://blazedemo.com/", ENDITEM, 
		LAST);

	lr_end_transaction("01", LR_AUTO);


	web_add_auto_header("Origin", 
		"https://blazedemo.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"87\", \" Not;A Brand\";v=\"99\", \"Chromium\";v=\"87\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	lr_think_time(15);

	lr_start_transaction("02");

		web_submit_form("reserve.php", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=fromPort", "Value=Boston", ENDITEM, 
		"Name=toPort", "Value=Cairo", ENDITEM, 
		LAST);

	lr_end_transaction("02", LR_AUTO);


	lr_think_time(11);

	web_submit_form("purchase.php", 
		"Ordinal=3", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		LAST);

	lr_think_time(20);

	lr_start_transaction("03");

		web_submit_form("confirmation.php", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=inputName", "Value=Test", ENDITEM, 
		"Name=address", "Value=Test", ENDITEM, 
		"Name=city", "Value=Test", ENDITEM, 
		"Name=state", "Value=Test", ENDITEM, 
		"Name=zipCode", "Value=123456", ENDITEM, 
		"Name=cardType", "Value=Visa", ENDITEM, 
		"Name=creditCardNumber", "Value=12345", ENDITEM, 
		"Name=creditCardMonth", "Value=11", ENDITEM, 
		"Name=creditCardYear", "Value=2017", ENDITEM, 
		"Name=nameOnCard", "Value=John Smith", ENDITEM, 
		"Name=rememberMe", "Value=<OFF>", ENDITEM, 
		LAST);


	lr_end_transaction("03", LR_AUTO);

	return 0;
}
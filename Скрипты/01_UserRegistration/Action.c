Action()
{
lr_start_transaction("01_UserRegistration");
	
lr_start_transaction("WebTours");


web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST);


	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
lr_end_transaction("WebTours", LR_AUTO);

lr_start_transaction("GoSingUp");

web_reg_find("Text=Customer Profile", 
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t10.inf", 
		LAST);
	lr_end_transaction("GoSingUp", LR_AUTO);
	
	lr_think_time(9);

	lr_start_transaction("InputUserData");
	
	web_reg_find("Text=Thank you, <b>{UserName}</b>, for registering and welcome to the Web Tours family.", 
		LAST);
	
	web_submit_form("login.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=passwordConfirm", "Value={Password}", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=78", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

lr_end_transaction("InputUserData", LR_AUTO);

	lr_think_time(20);
	lr_start_transaction("CompliteRegestration");
	
	web_reg_find("Text=Welcome, <b>{UserName}</b>, to the Web Tours reservation pages.", 
		LAST);
	
	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t12.inf", 
		LAST);
	
lr_end_transaction("CompliteRegestration", LR_AUTO);
	lr_think_time(5);
	
	lr_start_transaction("Logout");
	
	web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST); 
	
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t13.inf", 
		LAST);
lr_end_transaction("Logout", LR_AUTO);

lr_end_transaction("01_UserRegistration", LR_AUTO);

	return 0;
}
Action()
{

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t10.inf", 
		LAST);

	lr_think_time(9);

	
	 Users[10][2];

	for (int i=0;i<10;i++)
		for(int j=0;j<2;j++){
		Users[i][j]=rand()%90+65;
		print(User[i][j]+'\n');
	}
	
	web_submit_form("login.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=username", "Value=User[i][j]", ENDITEM, 
		"Name=password", "Value=User[i][j]", ENDITEM, 
		"Name=passwordConfirm", "Value=User[i][j]", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=78", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	lr_think_time(20);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t12.inf", 
		LAST);

	lr_think_time(5);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t13.inf", 
		LAST);

	return 0;
}
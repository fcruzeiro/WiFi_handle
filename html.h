#ifndef HTML_H
#define HTML_H
#endif

const String APs="<!DOCTYPE html>\n \
\n \
<html lang='en' xmlns='http://www.w3.org/1999/xhtml'>\n \
<head>\n \
    <meta charset='utf-8' />\n \
    <title>WiFi Setup1</title>\n \
\n \
</head>\n \
<style type='text/css'>\n \
    .auto-style1 {\n \
        text-align: left;\n \
    }\n \
\n \
    .auto-style2 {\n \
        font-size: 50px;\n \
        margin-top: 100px;\n \
    }\n \
\n \
    select {\n \
        height: 110px;\n \
        font-size: 90px;\n \
        width: 1284px;\n \
        margin-bottom: 50px;\n \
        border-radius:30px;\n \
    }\n \
\n \
    div {\n \
        text-align: center\n \
    }\n \
</style>\n \
\n \
<body>\n \
\n \
    <body style='background-color:gray; text-align: center;width:1284px;height:27784px'>\n \
        <div style='text-align: center;'>\n \
            <span><h1 style='background-color:blue ; color:white;font-size:120px '> WiFiSetup</h1></span>\n \
        </div>\n \
        <form method='POST'>\n \
            <div class='auto-style1'>\n \
                <label for='sid'><span class='auto-style2'>SSID:</span></label>\n \
                <select name='Select1' id='sid'>\n opcoes \
                </select>\n \
                &nbsp;\n \
                <label for='PWD1'><span class='auto-style2'>SENHA:</span></label>\n \
                <input name='Pwd1' id='PWD1' style='width:1200px;height:110px;border-radius:30px; margin-bottom:50px;font-size: 90px;' type='password'>\n \
                <div>\n \
                    <input class='auto-style2' name='Button1' type='submit' value='Confirma'\n \
                           style='border-radius:30px;background-color:darkgoldenrod; height: 110px;margin:auto; width:50%; font-size:90px'>\n \
                </div>\n \
            </div>\n \
        </form>\n \
    </body>\n \
</html>\n \
\n \
";

import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header

# 第三方 SMTP 服务
mail_host = "smtp.126.com"  # SMTP服务器
mail_user = "robotlsc"  # 用户名
mail_pass = "HKRBJYWSPEWKQUFM"  # 密码(这里的密码不是登录邮箱密码，而是授权码)

sender = 'robotlsc@126.com'  # 发件人邮箱
receivers = ['2790099263@qq.com']  # 接收人邮箱

f=open("test.txt","r")
content = f.read()
f.close()
title = '最近的DDL项目'  # 邮件主题
message = MIMEText(content, 'plain', 'utf-8')  # 内容, 格式, 编码
message['From'] = "{}".format(sender)
message['To'] = ",".join(receivers)
message['Subject'] = title

try:
    smtpObj = smtplib.SMTP_SSL(mail_host, 465)  # 启用SSL发信, 端口一般是465
    smtpObj.login(mail_user, mail_pass)  # 登录验证
    smtpObj.sendmail(sender, receivers, message.as_string())  # 发送
    print("mail has been send successfully.")
except smtplib.SMTPException as e:
    print(e)
import smtplib
import os
import time
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders

# Set email parameters
smtp_server = "smtp.gmail.com"  # or any other SMTP server
smtp_port = 587  # or any other SMTP port
username = "sendes2023@gmail.com"  # your email address
password = "senDe$2023!"  # your email password
from_email = "sendes2023@gmail.com"  # your email address
to_email = "user.smartcompost@gmail.com"  # recipient email address
subject = "CSV FILE READY"  # email subject
body = "Please see attached file."  # email body

# Set file parameters
file_path = "/home/pi/Downloads/logs.csv"  # replace with actual file path
file_name = "logs.csv"  # replace with actual file name

# Set interval time in seconds
interval =  21600  # six hours

while True:
    # Create email message
    msg = MIMEMultipart()
    msg['From'] = from_email
    msg['To'] = COMMASPACE.join([to_email])
    msg['Subject'] = subject
    msg.attach(MIMEText(body, 'plain'))

    # Attach file to email
    attachment = MIMEBase('application', "octet-stream")
    with open(file_path, 'rb') as f:
        attachment.set_payload(f.read())
    encoders.encode_base64(attachment)
    attachment.add_header('Content-Disposition', 'attachment', filename=file_name)
    msg.attach(attachment)

    # Send email
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(username, password)
    server.sendmail(from_email, [to_email], msg.as_string())
    server.quit()

    # Wait for next interval
    time.sleep(interval)


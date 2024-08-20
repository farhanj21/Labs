require('dotenv').config();
const nodemailer = require('nodemailer');

const transporter = nodemailer.createTransport({
  service: 'gmail',
  auth: {
    user: process.env.GMAIL_USER,
    pass: process.env.GMAIL_PASS,
  },
});

const sendEmail = (to, subject, text) => {
  const mailOptions = {
    from: process.env.GMAIL_USER,
    to: to,
    subject: subject,
    text: text,
  };

  transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
      return console.log('Error occurred: ', error.message);
    }
    console.log('Email sent: ', info.response);
  });
};

sendEmail('recipient@example.com', 'Test Subject', 'This is a test email sent using Nodemailer.');

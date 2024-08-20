const fs = require('fs');
const path = require('path');

const users = [
  {
    name: 'Shaaf Salman',
    image: 'https://example.com/shaaf.jpg',
    content: 'This is the content for Shaaf'
  },
  {
    name: 'Farhan Jafri',
    image: 'https://example.com/farhan.jpg',
    content: 'This is the content for Farhan'
  }
];

users.forEach(user => {
  const html = `
    <!DOCTYPE html>
    <html>
      <head>
        <title>${user.name}</title>
      </head>
      <body>
        <h1>${user.name}</h1>
        <img src="${user.image}" alt="${user.name}">
        <p>${user.content}</p>
      </body>
    </html>
  `;

  const filePath = path.join(__dirname, `${user.name}.html`);
  fs.writeFileSync(filePath, html);
});
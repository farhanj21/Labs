const fs = require('fs');

const newPageHtml = `
<!DOCTYPE html>
<html>
  <head>
    <title>Web Quiz 2</title>
  </head>
  <body>
    <h1>This is Question 2</h1>
  </body>
</html>
`;

fs.writeFile('new_page.html', newPageHtml, (err) => {
  if (err) {
    console.error('Error writing file:', err);
    return;
  }

  console.log('File written: new_page.html');
});
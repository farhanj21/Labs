const fs = require('fs');

const newPageHtml = `
<!DOCTYPE html>
<html>
  <head>
    <title>New Page</title>
  </head>
  <body>
    <h1>Create Files Part 1</h1>
  </body>
</html>
`;

fs.writeFile('newpage.html', newPageHtml, (err) => {
  if (err) {
    console.error('Error writing file:', err);
    return;
  }

  console.log('File written successfully: new_page.html');
});
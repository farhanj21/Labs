const fs = require('fs').promises;

async function readIndexHtml() {
  try {
    const data = await fs.readFile('index.html', 'utf-8');
    console.log(data);
  } catch (error) {
    console.error(`Error reading file: ${error.message}`);
  }
}

readIndexHtml();
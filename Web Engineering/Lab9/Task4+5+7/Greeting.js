import React, { useState } from 'react';

const Greeting = ({ name }) => {
  const [storedName, setStoredName] = useState(name);

  const handleNameChange = (event) => {
    setStoredName(event.target.value);
  };

  return (
    <div>
      <h2>Hello, {storedName}!</h2>
      <input type="text" value={storedName} onChange={handleNameChange} />
    </div>
  );
};

export default Greeting;
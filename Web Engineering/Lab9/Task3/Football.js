import React from 'react';

const Football = () => {
  // Define the shoot function
  const shoot = (a) => {
    alert(a);
  };

  // Bind the shoot function to the onClick event of the button
  return (
    <div className="center">
      <button onClick={() => shoot('Goal!')} className="button">
        SHOOT
      </button>
    </div>
  );
};

export default Football;
import React, { useState } from 'react';
import './App.css';

const Calculator = () => {
  const [displayValue, setVal] = useState('0');

  const clickDigit = (num) => {
    if (displayValue === '0') {
      setVal(num.toString());
    } else {
      setVal(displayValue + num.toString());
    }
  };    

  const clickOperation = (op) => {
    if (displayValue === op) return;
    setVal(displayValue + op);
  };

  const clickClear = () => {setVal('0'); };

  const clickEqual = () => {
      setVal(eval(displayValue).toString());
  };

  const showButton = (num) => (
    <button key={num} onClick={() => clickDigit(num)}>{num}</button>
  );

  return (
    <div className="calculator">
      <div className="display">{displayValue}</div>
      <div className="buttons">
        
        {showButton(1)} 
        {showButton(2)} 
        {showButton(3)}
        <button onClick={() => clickOperation('/')}>/</button>
        {showButton(4)} 
        {showButton(5)} 
        {showButton(6)}
        <button onClick={() => clickOperation('*')}>*</button>
        {showButton(7)} 
        {showButton(8)} 
        {showButton(9)}
        <button onClick={() => clickOperation('-')}>-</button>

        <button type onClick={clickClear}>C</button>
       
        {showButton(0)}
        <button onClick={() => clickOperation('+')}>+</button>
        <button onClick={clickEqual}>=</button>
      </div>
    </div>
  );
};

export default Calculator;
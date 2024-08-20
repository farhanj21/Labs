import React from 'react';
import UserForm from './UserForm';
import Clock from './Clock';
import Greeting from './Greeting';
import './App.css';

function App() {
  
  //task 7 
  // return (
  //   <div className='app-container'>
  //     <h1>User Form</h1>
  //     <UserForm />
  //   </div>
  // );

  //task 5
  // return (
  //   <div className='app-container'>
  //     <Clock />
  //   </div>
  // );

  //task 4
  return (
    <div className='app-container'>
      <Greeting name="Farhan" />
    </div>
  );


}


export default App;




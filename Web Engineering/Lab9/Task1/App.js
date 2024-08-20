import React from 'react';
import Mailbox from './Mailbox';

const messages = ['React', 'Re: React', 'Re:Re: React'];

const App = () => {
  return <Mailbox unreadMessages={messages} />;

  
};

export default App;



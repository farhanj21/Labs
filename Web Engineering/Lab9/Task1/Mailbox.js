import React from 'react';
import './App.css'

const Mailbox = ({ unreadMessages }) => {
  const hasUnreadMessages = unreadMessages.length > 0;

  return (
    <div className='mailbox'>
      <h1>Hello!</h1>
      {hasUnreadMessages && (
        <p>You have {unreadMessages.length} unread messages.</p>
      )}
    </div>
  );
};

export default Mailbox;
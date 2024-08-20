import React, { useRef } from 'react';

function ScrollToTopButton() {
  const header = useRef(null); 

  const handleScrollToTop = () => {
    if (header.current) 
    {
        header.current.scrollIntoView ({
        behavior: 'smooth',
        block: 'start',
      });
    }
  };

  return (
    <div >
      <div ref={header} />

      <h1  style={{ marginBottom: '1000px' }}>
        This is Lab 9 of Web Engineering
      
      </h1>

      <button className='button' onClick={handleScrollToTop}>Scroll to Top</button>
    </div>
  );
}

export default ScrollToTopButton;
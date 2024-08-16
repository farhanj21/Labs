package org.example;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingWorkerQ4 extends JFrame
{
    private JProgressBar progressBar;
    private JButton startButton;

    public SwingWorkerQ4() {
        super("SwingWorker Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 150);
        setLocationRelativeTo(null);

        progressBar = new JProgressBar(0, 100);
        progressBar.setStringPainted(true);

        startButton = new JButton("Start Task");
        startButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                startButton.setEnabled(false);
                new BackgroundTask().execute();
            }
        });

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 1));
        panel.add(progressBar);
        panel.add(startButton);

        add(panel);
    }

    private class BackgroundTask extends SwingWorker<Void, Integer> {
        @Override
        protected Void doInBackground() throws Exception {
            int progress = 0;
            while (progress < 100) {
                Thread.sleep(100);
                progress += 5;
                publish(progress);
            }
            return null;
        }

        @Override
        protected void process(java.util.List<Integer> chunks) {
            int latestProgress = chunks.get(chunks.size() - 1);
            progressBar.setValue(latestProgress);
        }

        @Override
        protected void done() {
            startButton.setEnabled(true);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SwingWorkerQ4().setVisible(true);
            }
        });
    }
}
import java.io.*;
import java.util.HashMap;
import java.util.Map;

class FileSerializable implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private String fileId, fileName, fileOwner;
    private long size;
    private byte[] content;

    public FileSerializable(String fileId, String fileName, long size, String fileOwner, byte[] content) {
        this.fileId = fileId;
        this.fileName = fileName;
        this.size = size;
        this.fileOwner = fileOwner;
        this.content = content;
    }

    public String getFileId() 
    { 
           return fileId; 
    }
    public String getFileName() 
    { 
        return fileName; 
    }
    public long getSize() 
    { 
        return size; 
    }
    public String getOwner() 
    { 
        return fileOwner; 
    }
    public byte[] getContent() 
    { 
        return content; 
    }

    public void setFileId(String fileId) 
    { 
        this.fileId = fileId; 
    }
    public void setFileName(String fileName) 
    { 
        this.fileName = fileName; 
    }
    public void setSize(long size) 
    { 
        this.size = size; 
    }
    public void setOwner(String fileOwner) 
    { 
        this.fileOwner = fileOwner; 
    }
    public void setContent(byte[] content) 
    { 
        this.content = content; 
    }
}

public class FileManagementSystem {
    private Map<String, FileSerializable> files;

    public FileManagementSystem() {
        files = new HashMap<>();
    }

    public void addFile(String fileId, String fileName, String fileOwner, byte[] content) throws IOException {
        if (files.containsKey(fileId)) {
            throw new IllegalArgumentException("File already exists");
        }
        
        FileSerializable file = new FileSerializable(fileId, fileName, content.length, fileOwner, content);
        files.put(fileId, file);
        serializeFile(file);
    }

    public void listFiles() 
    {
        for (String fileId : files.keySet()) {
            System.out.println("ID: " + fileId + ", File Name: " + files.get(fileId).getFileName());
        }
    }

    private void serializeFile(FileSerializable file) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(file.getFileId() + ".dat"))) {
            out.writeObject(file);
        }
    }

    public void loadFile(String fileId) throws IOException, ClassNotFoundException {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileId + ".dat"))) {
            FileSerializable file = (FileSerializable) in.readObject();
            files.put(fileId, file);
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error reading file: " + e.getMessage());
            throw e;
        }
    }

    public static void main(String[] args) {
        FileManagementSystem obj = new FileManagementSystem();
        
        try {
            obj.addFile("1", "Lab8.txt", "Farhan", "Inshallah Pakistan will win vs New Zealand.".getBytes());
            obj.listFiles();
            obj.loadFile("1");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

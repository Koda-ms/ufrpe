package cooperacaoSemaforo;

public class ThreadInserir extends Thread {

    private final BufferSemaforo buffer;
    private final char id;
    private boolean exit;

    public ThreadInserir(BufferSemaforo buf, char id, boolean exit) {
        this.buffer = buf;
        this.id = id;
        this.exit = exit;
    }

    @Override
    public void run() {
        for (int i = 0; i < 500; i++) {
            
            if(exit == true){
                break;
            }
            buffer.inserir(id);
            try {
                sleep((long) 30);
            } catch (InterruptedException ie) {
            }
        }
        System.out.println("Thread " + id + " terminou\n");
    }

    public void meuStop(){
       this.exit = true;
    }
}

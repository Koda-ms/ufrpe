package cooperacaoSemaforo;

public class ThreadEsvaziar extends Thread {

    private final BufferSemaforo buf;
    private final char id;

    public ThreadEsvaziar(BufferSemaforo buf, char id) {
        this.buf = buf;
        this.id = id;
    }

    @Override
    public void run() {
        String result;
        for (int i = 0; i < 10; i++) {

            result = buf.esvaziar();
            System.out.println("\n\nImpressao # " + (i + 1) + " - Thread ("+id+"):\n Buffer = "
                    + result + " -> Tamanho: " + result.length());
        }
        System.out.println("ThreadEsvaziar terminou");
    }
}

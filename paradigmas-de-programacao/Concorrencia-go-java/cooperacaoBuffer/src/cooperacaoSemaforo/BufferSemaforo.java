package cooperacaoSemaforo;

import java.util.concurrent.Semaphore;

/**
 * Similar a classe BufferWaitNotify porém usa Semáforo no lugar de wait/notify
 * @author sidneynogueira
 */
public class BufferSemaforo {

    private final char[] buf;
    private int tam;
    private final int MAX = 100;
    private final Semaphore semaforoConsumidor;
    private final Semaphore semaforoProdutor;

    public BufferSemaforo() {
        semaforoConsumidor = new Semaphore(0);//acquire/release
        semaforoProdutor = new Semaphore(1);
        buf = new char[MAX];
        tam = 0;
    }
    
    public void inserir(char c){
        
        if(tam == MAX){
            semaforoConsumidor.release();
            try {
                semaforoProdutor.acquire();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else{
            buf[tam++] = c;
        }
        
    }

    public String esvaziar() {
        try {
            semaforoConsumidor.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        tam = 0;
        semaforoProdutor.release();
        return new String(buf);
    }

}

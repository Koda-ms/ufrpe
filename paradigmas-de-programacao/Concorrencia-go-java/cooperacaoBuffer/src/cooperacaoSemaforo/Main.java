package cooperacaoSemaforo;

public class Main {

    public static void main(String[] args) {
        int num_inserir = 4, num_esvaziar = 2;
        BufferSemaforo buf = new BufferSemaforo();

        ThreadInserir[] her = new ThreadInserir[num_inserir];
        for(int i = 0; i < num_inserir; i++){
            her[i] = new ThreadInserir(buf, Character.forDigit(i+1,10),false);
            her[i].start();
        }

        ThreadEsvaziar[] imp1 = new ThreadEsvaziar[num_esvaziar];
        for(int j = 0; j < num_esvaziar; j++){
            imp1[j] = new ThreadEsvaziar(buf, Character.forDigit(j+1,10));
            imp1[j].start();
            try {
                imp1[j].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        for(int i = 0; i < num_inserir; i++){
            her[i].meuStop();
        }
    }

}

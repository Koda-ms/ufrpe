// Gerar stubs para comunicação remota com o comando "rmic -keep Calculadora"
// Rodar o servidor com o comando "java -Djava.security.policy=nome_do_arquivo_com_as_politicas ServidorRMIMain"

package questao01.servidorRMI;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import questao01.calcRMIinterface.ICalculadora;

public class ServidorMain {
    
    public static void main(String[] args) {

        try {
            // cria um objeto para ser acessado via rede
            ICalculadora calc = new Calculadora();
            String nomeObjeto = "rmi://localhost/Calc";

            // registra o objeto no RMIRegistry
            Registry registry = LocateRegistry.createRegistry(5509);
            // associa o nome do objeto ao objeto
            registry.rebind(nomeObjeto, calc);

            System.out.println("Servidor pronto!");
            
        } catch (RemoteException e) {
            e.printStackTrace();
            return;
        }
    }
}
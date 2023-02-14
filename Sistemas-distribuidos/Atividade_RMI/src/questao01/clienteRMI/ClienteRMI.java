// Rodar o servidor com o comando "java -Djava.security.policy=nome_do_arquivo_com_as_politicas ClienteRMI"

package questao01.clienteRMI;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import questao01.calcRMIinterface.ICalculadora;

public class ClienteRMI {
    
    public static void main(String[] args){

        try {

            Registry reg = LocateRegistry.getRegistry(5509);
            // associa o registro (a porta) ao endereço abaixo
            ICalculadora calc = (ICalculadora) reg.lookup("rmi://localhost/Calc");
            System.out.println("O resultado da multiplicação é: " + calc.multiplicacao(5.2, 6));
            
        } catch (NotBoundException e) {
            e.printStackTrace();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
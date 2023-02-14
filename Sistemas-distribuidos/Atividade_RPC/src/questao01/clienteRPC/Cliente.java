package questao01.clienteRPC;

import java.net.URL;
import java.rmi.server.ObjID;

import org.apache.xmlrpc.client.XmlRpcClient;
import org.apache.xmlrpc.client.XmlRpcClientConfigImpl;
import org.apache.xmlrpc.client.XmlRpcCommonsTransportFactory;

public class Cliente {
    
    private XmlRpcClient cliente;

    public static void main(String[] args) {

        try {
            XmlRpcClientConfigImpl clientConfig = new XmlRpcClientConfigImpl();
            clientConfig.setServerURL(new URL("http://localhost:8185"));
            
            //clientConfig.setEnabledForExceptions(true);

            XmlRpcClient client = new XmlRpcClient();
            client.setTransportFactory(new XmlRpcCommonsTransportFactory(client));
            client.setConfig(clientConfig);

            Object[] params = new Object[]{2.0,3.0};
            double result = (double) client.execute("Calculadora.soma", params);

            System.out.println("O Resultado da soma é: " + result);   

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}

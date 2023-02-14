package questao01.servidorRPC;

import java.io.IOException;

import org.apache.xmlrpc.XmlRpcException;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.server.XmlRpcServer;
//import org.apache.xmlrpc.server.XmlRpcServerConfigImpl;
import org.apache.xmlrpc.webserver.WebServer;

public class Servidor {
    
    public static void main(String[] args) {
        
        try {
            // cria um servidor web na porta 8185
            WebServer ws = new WebServer(8185);
            XmlRpcServer server = ws.getXmlRpcServer();

            // adiciona um "handler" a PHM
            PropertyHandlerMapping phm = new PropertyHandlerMapping();
            phm.addHandler("Calculadora", Calculadora.class);
            // define o "handler" no servidor
            server.setHandlerMapping(phm);

            // habilita valores float
            // XmlRpcServerConfigImpl serverConfig = (XmlRpcServerConfigImpl) server.getConfig();
            // serverConfig.setEnabledForExtensions(true);
            
            // inicia o servidor web
            ws.start();
            System.out.println("Servidor iniciado com sucesso!");

        } catch (IOException | XmlRpcException e) {
            e.printStackTrace();
        }
    }

}
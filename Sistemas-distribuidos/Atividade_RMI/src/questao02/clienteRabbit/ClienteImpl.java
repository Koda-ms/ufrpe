//Para executar o código:
//java -cp "amqp-client-5.16.0.jar;slf4j-api-1.7.36.jar;slf4j-simple-1.7.36.jar;." questao02.clienteRabbit.ClienteImpl

package questao02.clienteRabbit;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.Channel;

public class ClienteImpl {
    
    // Fila para designar tarefas
    private final static String CALC_QUEUE = "calc";

    public static void main(String[] args) throws TimeoutException, IOException {
        
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");

        try(Connection connection = factory.newConnection();
            Channel channel = connection.createChannel()
        ){
            channel.queueDeclare(CALC_QUEUE, false, false, false, null);
            String message = "raiz 9";

            channel.basicPublish("", CALC_QUEUE, null, message.getBytes());
            System.out.println(" Valores enviados: " + message + "");
        }
    }

}
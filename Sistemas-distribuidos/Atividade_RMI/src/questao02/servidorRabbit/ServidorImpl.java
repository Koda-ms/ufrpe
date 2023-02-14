//Para executar o código:
//java -cp "amqp-client-5.16.0.jar;slf4j-api-1.7.36.jar;slf4j-simple-1.7.36.jar;." questao02.servidorRabbit.ServidorImpl

package questao02.servidorRabbit;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

public class ServidorImpl {

    private final static String CALC_QUEUE = "calc";

    public static void main(String[] args) throws TimeoutException, IOException {
        
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");

        Connection connect = factory.newConnection();
        Channel channel = connect.createChannel();
        channel.queueDeclare(CALC_QUEUE, false, false, false, null);
        
        System.out.println("Esperando mensagens...");
    
        DeliverCallback deliverCallback = (consumerTag, delivery) -> {

            String message = new String(delivery.getBody(), "UTF-8");
            String[] operationDetail = message.split(" ");
            double result = 0;

            switch (operationDetail[0]) {
                case "somar":
                    result = Double.parseDouble(operationDetail[1]) + Double.parseDouble(operationDetail[2]);
                    break;
                case "subtrair":
                    result = Double.parseDouble(operationDetail[1]) - Double.parseDouble(operationDetail[2]);
                    break;
                case "multiplicar":
                    result = Double.parseDouble(operationDetail[1]) * Double.parseDouble(operationDetail[2]);
                    break;
                case "dividir":
                    result = Double.parseDouble(operationDetail[1]) / Double.parseDouble(operationDetail[2]);
                    break;
                case "ln":
                    result = Math.log(Double.parseDouble(operationDetail[1]));
                    break;
                case "log10":
                    result = Math.log10(Double.parseDouble(operationDetail[1]));
                    break;
                case "expo":
                    result = Math.pow(Double.parseDouble(operationDetail[1]), Double.parseDouble(operationDetail[2]));
                    break;
                case "seno":
                    result = Double.parseDouble(operationDetail[1]) / Double.parseDouble(operationDetail[2]);
                    break;
                case "cosseno":
                    result = Double.parseDouble(operationDetail[1]) / Double.parseDouble(operationDetail[2]);
                    break;
                case "raiz":
                    result = Math.sqrt(Double.parseDouble(operationDetail[1]));
                    break;
                default:
                    System.out.println("Opção inválida!");
                    break;
            }
            
            System.out.println("Recebido! O resultado é: " + result);
        };

        channel.basicConsume(CALC_QUEUE, true, deliverCallback, consumerTag -> { });
    }
}
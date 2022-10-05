package questao04;

import java.time.LocalDate;
import java.util.List;

import javafx.application.Application;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.negocio.ControladorAlertaPreco;
import questao04.negocio.ControladorLoja;
import questao04.negocio.ControladorOfertaProduto;
import questao04.negocio.ControladorProduto;
import questao04.negocio.ControladorUsuario;
import questao04.negocio.beans.AlertaPreco;
import questao04.negocio.beans.CategoriaProduto;
import questao04.negocio.beans.Loja;
import questao04.negocio.beans.OfertaProduto;
import questao04.negocio.beans.Produto;
import questao04.negocio.beans.Usuario;

public class Principal extends Application{

	//Necessário para lançar as telas do JavaFX
	public static void main(String[] args){
		launch(args);
	}	
		
	@Override
	public void start(Stage stage) throws ObjetoJaAdicionadoException {
		
		ControladorUsuario usuario = new ControladorUsuario();
		//Instanciando 1 usuário
		Usuario juvenal = new Usuario("juvenal@gmail.com", "Juvenal Ribeiro", LocalDate.of(1987, 2, 8));
		
		try {
			usuario.adicionar(juvenal);
		} catch (ObjetoJaAdicionadoException e) {
			e.getMessage();
		}
		
		ControladorProduto produto = new ControladorProduto();
		//Instanciando 2 produtos
		Produto notebook = new Produto("003", "Notebook Acer", "Aspire 5", CategoriaProduto.ELETRONICOS);
		Produto calca = new Produto("123", "Calça Moletom Calvin Klein", "Calça meia perna", CategoriaProduto.VESTUARIO);
		
		try {
			produto.adicionar(notebook);
			produto.adicionar(calca);
		} catch (ObjetoJaAdicionadoException e) {
			e.getMessage();
		}
		
		ControladorAlertaPreco alerta = new ControladorAlertaPreco();
		//Instanciando 2 alertas (1 para cada produto)
		AlertaPreco alerta1 = new AlertaPreco(juvenal, notebook, 2500);
		AlertaPreco alerta2 = new AlertaPreco(juvenal, calca, 200);
		
		try {
			alerta.adicionar(alerta1);
			alerta.adicionar(alerta2);
		} catch (ObjetoJaAdicionadoException e) {
			e.getMessage();
		}
		
		ControladorLoja loja = new ControladorLoja();
		//Instanciando 3 lojas
		Loja loja1 = new Loja("62.865.736/0001-80", "Americanas", "www.americanas.com.br");
		Loja loja2 = new Loja("71.404.785/0001-06", "Magazine Luiza", "www.magaineluiza.com.br");
		Loja loja3 = new Loja("15.659.220/0001-07", "C&A", "www.cea.com.br");
		
		try {
			loja.adicionar(loja1);
			loja.adicionar(loja2);
			loja.adicionar(loja3);
		} catch (ObjetoJaAdicionadoException e) {
			e.getMessage();
		}
		
		ControladorOfertaProduto oferta = new ControladorOfertaProduto();
		//Instanciando 12 ofertas de produtos (4 para cada loja)
		OfertaProduto oferta1Loja1 = new OfertaProduto(loja1, notebook, LocalDate.of(2022, 3, 27), 3230);
		OfertaProduto oferta2Loja1 = new OfertaProduto(loja1, calca, LocalDate.of(2021, 5, 10), 320);
		OfertaProduto oferta3Loja1 = new OfertaProduto(loja1, notebook, LocalDate.of(2021, 6, 27), 2490);
		OfertaProduto oferta4Loja1 = new OfertaProduto(loja1, calca, LocalDate.of(2021, 8, 2), 180);
		
		OfertaProduto oferta1Loja2 = new OfertaProduto(loja2, notebook, LocalDate.of(2022, 4, 9), 2399);
		OfertaProduto oferta2Loja2 = new OfertaProduto(loja2, calca, LocalDate.of(2021, 12, 12), 215);
		OfertaProduto oferta3Loja2 = new OfertaProduto(loja2, notebook, LocalDate.of(2022, 4, 9), 4010);
		OfertaProduto oferta4Loja2 = new OfertaProduto(loja2, calca, LocalDate.of(2021, 6, 20), 250);
		
		OfertaProduto oferta1Loja3 = new OfertaProduto(loja3, notebook, LocalDate.of(2022, 4, 9), 3099);
		OfertaProduto oferta2Loja3 = new OfertaProduto(loja3, calca, LocalDate.of(2021, 2, 9), 200);
		OfertaProduto oferta3Loja3 = new OfertaProduto(loja3, notebook, LocalDate.of(2022, 3, 27), 2600);
		OfertaProduto oferta4Loja3 = new OfertaProduto(loja3, calca, LocalDate.of(2022, 3, 27), 309);
		
		try {
			oferta.adicionar(oferta1Loja1);
			oferta.adicionar(oferta2Loja1);
			oferta.adicionar(oferta3Loja1);
			oferta.adicionar(oferta4Loja1);
			oferta.adicionar(oferta1Loja2);
			oferta.adicionar(oferta2Loja2);
			oferta.adicionar(oferta3Loja2);
			oferta.adicionar(oferta4Loja2);
			oferta.adicionar(oferta1Loja3);
			oferta.adicionar(oferta2Loja3);
			oferta.adicionar(oferta3Loja3);
			oferta.adicionar(oferta4Loja3);
		} catch (ObjetoJaAdicionadoException e) {
			e.getMessage();
		}
		
		System.out.println("Lista de Ofertas");
		System.out.println("-------------------------------------------------------------------------");
		
		LocalDate dataHoje = LocalDate.now();

        List<OfertaProduto> ofertaNotebook = oferta.listarOfertasOrdenadasPorPrecoNaData(notebook,dataHoje);

        for (OfertaProduto ofertas : ofertaNotebook) {
            System.out.printf("%-8s\t |\tR$ %,.2f\t|\t%s\n",ofertas.getLoja().getNome(),ofertas.getPrecoOferta(),
            		ofertas.getLoja().getSite());
        }
        
        System.out.println("-------------------------------------------------------------------------");
        
		System.out.println();
		
		//TODO Método toString() não imprime corretamente
        System.out.println("Histórico de Ofertas do Produto");
		System.out.println("-------------------------------------------------------------------------");
		
		LocalDate dataFinal = LocalDate.of(2022, 4, 12);
		
        System.out.println(oferta.montarHistoricoDeOfertasDoProdutoNoPeriodo(notebook, dataHoje, dataFinal));
        
        System.out.println("-------------------------------------------------------------------------");
		//Execução do método verificarAlertasDePrecoAtingido() e configuração de alerta para cada retorno 
        
        //Um problema está acontecendo com esse método: ele está alertando o produto "Notebook" mais vezes
        //do que o necessário.
		for(AlertaPreco gerarAlerta : alerta.verificarAlertasDePrecoAtingido(juvenal, oferta)) {
			Alert alertaOferta = new Alert(Alert.AlertType.WARNING);
			alertaOferta.setTitle("Alerta de Oferta");
			alertaOferta.setHeaderText("Seu produto está em oferta e esperando por você!");
			alertaOferta.setContentText(gerarAlerta.toString());
			alertaOferta.showAndWait();
		}
	}
}

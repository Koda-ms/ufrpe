package questao04.negocio;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import questao04.dados.IRepositorioGenerico;
import questao04.dados.RepositorioGenerico;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;
import questao04.negocio.beans.OfertaProduto;
import questao04.negocio.beans.Produto;

public class ControladorOfertaProduto{
	
	private IRepositorioGenerico<OfertaProduto> repoOfertaProduto;

	public ControladorOfertaProduto() {
		this.repoOfertaProduto = new RepositorioGenerico<>();
	}
	
	public void adicionar(OfertaProduto op) throws ObjetoJaAdicionadoException {
		this.repoOfertaProduto.adicionarObjetos(op);
	}
	
	public void remover(OfertaProduto op) throws ObjetoNaoExisteException {
		this.repoOfertaProduto.removerObjetos(op);
	}
	
	public void atualziar(OfertaProduto op) throws ObjetoNaoExisteException {
		this.repoOfertaProduto.atualizarObjeto(op);
	}
	
	public List<OfertaProduto> listar(){
		return this.repoOfertaProduto.listar();
	}
	
	public List<OfertaProduto> listarOfertasOrdenadasPorPrecoNaData(Produto produto, LocalDate dataAtual){
		List<OfertaProduto> ofertasOrdenadasPorPreco = new ArrayList<>();
		
		for(OfertaProduto oferta : this.repoOfertaProduto.listar()) {
			if(oferta.getProduto().equals(produto) && dataAtual.isEqual(oferta.getData())) {
				ofertasOrdenadasPorPreco.add(oferta);
			}
		}
		//Ordenação da lista
		Collections.sort(ofertasOrdenadasPorPreco);
		
		return ofertasOrdenadasPorPreco;
	}
	
	public Map<LocalDate, List<OfertaProduto>> montarHistoricoDeOfertasDoProdutoNoPeriodo(Produto produto, LocalDate dataInicial, LocalDate dataFinal){
		Map<LocalDate, List<OfertaProduto>> result = new HashMap<>();
		
		//Partindo do princípio que a dataAtual é anterior à dataFinal
		LocalDate dataAtual = dataInicial;
		do {
			List<OfertaProduto> ofertasNaData = this.listarOfertasOrdenadasPorPrecoNaData(produto, dataAtual);
			result.put(dataAtual, ofertasNaData);
			dataAtual = dataAtual.plusDays(1);
		}while(!dataAtual.equals(dataFinal));
		
		return result;
	}
}

package questao04.negocio;

import java.util.ArrayList;
import java.util.List;

import questao04.dados.IRepositorioGenerico;
import questao04.dados.RepositorioGenerico;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;
import questao04.negocio.beans.AlertaPreco;
import questao04.negocio.beans.OfertaProduto;
import questao04.negocio.beans.Usuario;

public class ControladorAlertaPreco {
	
	private IRepositorioGenerico<AlertaPreco> repoAlertaPreco;
	
	public ControladorAlertaPreco() {
		this.repoAlertaPreco = new RepositorioGenerico<>();
	}
	
	public void adicionar(AlertaPreco obj) throws ObjetoJaAdicionadoException {
		this.repoAlertaPreco.adicionarObjetos(obj);
	}
	
	public void remover(AlertaPreco obj) throws ObjetoNaoExisteException {
		this.repoAlertaPreco.removerObjetos(obj);
	}
	
	public void atualizar(AlertaPreco obj) throws ObjetoNaoExisteException {
		this.repoAlertaPreco.atualizarObjeto(obj);
	}
	
	//Foi adicionado o parâmetro ControladorOfertaProduto ofertaP para comparar os preços do produto 
	//requisitado pelo usuário com os que existem na lista de oferta previamente setada  
	public List<AlertaPreco> verificarAlertasDePrecoAtingido(Usuario u, ControladorOfertaProduto ofertaP){
		
		List<AlertaPreco> alertaPrecosAntigosDoUsuario = new ArrayList<>();
		for(AlertaPreco ap : this.repoAlertaPreco.listar()) {
			if(ap.getUsuario() == u) {
				
				for(OfertaProduto op : ofertaP.listar()) {
					if(op.getPrecoOferta() <= ap.getPrecoDesejado()) {
						alertaPrecosAntigosDoUsuario.add(ap);
					}
				}
			}
		}
		return alertaPrecosAntigosDoUsuario;
	}
	
	public List<AlertaPreco> listarAlertasDePreco(){
		return this.repoAlertaPreco.listar();
	}
}

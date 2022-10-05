package questao04.negocio;

import java.util.List;

import questao04.dados.IRepositorioGenerico;
import questao04.dados.RepositorioGenerico;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;
import questao04.negocio.beans.Produto;
import questao04.negocio.beans.Usuario;

public class ControladorProduto {
	
	private IRepositorioGenerico<Produto> repoProduto;

	public ControladorProduto() {
		this.repoProduto = new RepositorioGenerico<>();
	}
	
	public void adicionar(Produto p) throws ObjetoJaAdicionadoException {
		this.repoProduto.adicionarObjetos(p);
	}
	
	public void remover(Produto p) throws ObjetoNaoExisteException {
		this.repoProduto.removerObjetos(p);
	}
	
	public void atualziar(Produto p) throws ObjetoNaoExisteException {
		this.repoProduto.atualizarObjeto(p);
	}
	
	public List<Produto> listar(){
		return this.repoProduto.listar();
	}
}

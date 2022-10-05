package questao01;

public class Estoque {

	private Produto produto;
	private int qtdAtual;
	private int qtdMinima;

	public Estoque() {
		super();
	}

	public Estoque(Produto produto, int qtdAtual, int qtdMinima) {
		super();
		this.produto = produto;
		this.qtdAtual = qtdAtual;
		this.qtdMinima = qtdMinima;
	}

	public Produto getProduto() {
		return produto;
	}

	public void setProduto(Produto produto) {
		this.produto = produto;
	}

	public int getQtdAtual() {
		return qtdAtual;
	}

	public void setQtdAtual(int qtdAtual) {
		this.qtdAtual = qtdAtual;
	}

	public int getQtdMinima() {
		return qtdMinima;
	}

	public void setQtdMinima(int qtdMinima) {
		this.qtdMinima = qtdMinima;
	}
	
	public void mudarQtdMinima(int qtdMinima) {
		this.qtdMinima = qtdMinima;
		//TODO later, test it without a variable, like this:
		//this.qtdMinima = qtdMinima;
	}
	
	public void reporEstoque(int qtd) {
		this.qtdAtual += qtd;
	}
	
	public void darBaixa(int qtd) {
		this.qtdAtual -= qtd;
	}
	
	public void relatorio() {
		System.out.println("Produto: " + produto.getNome());
		System.out.println("Quantidade Atual: " + this.qtdAtual);
		System.out.println("Quantidade Mínima: " + this.qtdMinima);
	}

}

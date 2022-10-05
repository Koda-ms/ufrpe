package questao04.negocio.beans;

public class AlertaPreco{
	
	private Usuario usuario;
	private Produto produto;
	private double precoDesejado;
	
	public AlertaPreco(Usuario usuario, Produto produto, double precoDesejado) {
		this.setPrecoDesejado(precoDesejado);
		this.setUsuario(usuario);
		this.setProduto(produto);
	}

	public Usuario getUsuario() {
		return usuario;
	}

	public void setUsuario(Usuario usuario) {
		this.usuario = usuario;
	}

	public Produto getProduto() {
		return produto;
	}

	public void setProduto(Produto produto) {
		this.produto = produto;
	}

	public double getPrecoDesejado() {
		return precoDesejado;
	}

	public void setPrecoDesejado(double precoDesejado) {
		this.precoDesejado = precoDesejado;
	}
	
	@Override
	public String toString() {
		return String.format("Usuário %s, o produto %s atingiu o seu preço desejado de R$%,.2f ", this.usuario, this.produto, this.precoDesejado);
	}
}

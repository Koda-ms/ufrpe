package questao04.negocio.beans;

import java.util.Objects;

public class Produto {

	private String codigo;
	private String nome;
	private String descricao;
	private CategoriaProduto categoria;

	public Produto(String codigo, String nome, String descricao, CategoriaProduto categoria) {
		this.setCodigo(codigo);
		this.setNome(nome);
		this.setDescricao(descricao);
		this.setCategoria(categoria);
	}

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		if(codigo != null) {
			this.codigo = codigo;
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if(nome != null) {
			this.nome = nome;
		}
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		if(descricao != null) {
			this.descricao = descricao;
		}
	}

	public CategoriaProduto getCategoria() {
		return categoria;
	}

	public void setCategoria(CategoriaProduto categoria) {
		if(categoria != null) {
			this.categoria = categoria;
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Produto other = (Produto) obj;
		return categoria == other.categoria && Objects.equals(codigo, other.codigo)
				&& Objects.equals(descricao, other.descricao) && Objects.equals(nome, other.nome);
	}

	@Override
	public String toString() {
		return String.format("%s (%s)", this.nome, this.descricao);
	}
}
